% Given a set of measurements on the bed surface, guess
% the tower endstop and DELTA_RADIUS errors that are most
% likely to have caused this distortion.
%
% Assumes delta bed coordinates are:
%
%      +Y                       3(RAMPS-Z)
%       ^                          X
%       |  Card coords            / \          Tower name/number
%       |                        /   \
%       +-->+X       (RAMPS-X)1 +-----+ 2 (RAMPS-Y)
%
%
% DeltaParams struct must contain:
%       RADIUS   -- Marlin DELTA_RADIUS, which is radius from tip to center
%                   of tower pivot for diagonal arm, minus effector offset
%                   (kind of a radius - effector_offset)
%       RodLen   -- length between center of pivots on diagonal rods
%
% RETURN:  values to ADD to DELTA_RADIUS and tower offset(M666 X Y Z)
%          settings to calibrate print bed
function [deltaErr, towerErr] = guessDeltaErr(DP,meas)

% initial data plot
figure(2);
hold off;
[c,ax,pFit] = plotParabolicFit(meas);
grid on;hold on;
plot3(meas(:,1),meas(:,2),meas(:,3),'+');
title('Parabolic fit to measurements, + is measurements, . are fit points');

GuessParams = DP;
GuessParams.meas = meas;
GuessParams.verbose = 0;
[dErr,nEval,status,err] = SimplexMinimize(...
              @(p) deltaGuessErr(p,GuessParams),...
   	      [0 0 0 0], 0.1+[0 0 0 0], 0.005+[0 0 0 0], 300)
deltaErr = dErr(1);
towerErr =-dErr(2:4);

% plot delta parameter fit
errZ = deltaErrZ(dErr,GuessParams);
plot3(meas(:,1),meas(:,2),errZ+meas(:,3),'r.');
#legend('Parabolic Fit to measurements','Measured','Delta Fit Points');
xlabel('X');ylabel('Y');
hold off

figure(3);
hold off;
fm = meas; fm(:,3) = fm(:,3)+errZ;
c = plotParabolicFit(fm);
grid on;hold on;
plot3(fm(:,1),fm(:,2),fm(:,3),'+');
hold off;
title('Parabolic Fit to simulated points');
xlabel('X');ylabel('Y');

figure(1);
hold off
plot3(meas(:,1),meas(:,2),meas(:,3),'+');
grid on;hold on;
plot3(meas(:,1),meas(:,2),errZ+meas(:,3),'rx');
legend('Measured','Fitted Points');
xlabel('X');ylabel('Y');
hold off

end

% Error metric for minimization
function err = deltaGuessErr(p,GP)
DP = struct('RodLen',GP.RodLen,...
            'RADIUS',GP.RADIUS+p(1));
err = deltaErrZ(p,GP);
err = mean(err .* err);
disp(sqrt(err))
end

% retrieve whole error vector
function errZ = deltaErrZ(p,GP)
DP = struct('RodLen',GP.RodLen,...
            'RADIUS',GP.RADIUS+p(1));
err = 0;
n = size(GP.meas,1);
errZ = zeros(n,1);
for i=1:n
  d0 = cart2delta(GP,GP.meas(i,1),GP.meas(i,2),0);
  de = d0 + p(2:4);  % delta positions with position offset error
  dz = delta2cart(DP,de(1),de(2),de(3));
  errZ(i) = dz(3) - GP.meas(i,3);
end
end

%%% Parabolic fit code.  Might move this to separate file(s) someday
function [c,ax,z] = plotParabolicFit(meas)
c = parabolicFit(meas)
% distance from origin of all measurements
r = sqrt(meas(:,1) .* meas(:,1) + meas(:,2) .* meas(:,2));
r5 = floor(max(r)/5)*5+5;  % r, rounded up to to neareast 5mm
ax = [-r5:5:r5];
n = length(ax);
z = zeros(n);
for i=1:n
   x = ax(i);
   for j=1:n
      y = ax(j);
      if (norm([x y]) <= r5)
         z(j,i) = parabola(c,x,y);
      end
   end
end
meshc(ax,ax,z);
end

function c = parabolicFit(meas)
A = ones(size(meas,1),6);
A(:,2:3) = meas(:,1:2);
A(:,4) = meas(:,1) .* meas(:,2);
A(:,5) = meas(:,1) .* meas(:,1);
A(:,6) = meas(:,2) .* meas(:,2);
c = inv(A' * A) * A' * meas(:,3);
end

function z = parabola(c,x,y)
z = c(1) + c(2)*x + c(3)*y + c(4)*x*y + c(5)*x*x + c(6)*y*y;
end

