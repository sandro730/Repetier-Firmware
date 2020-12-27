;
; First Calibration
;
G28         ; Home
;           ; M320 S<0/1> - Activate auto level, S1 stores it in eeprom
M321 S1     ; M321 S<0/1> - Deactivate auto level, S1 stores it in eeprom
M322        ; M322        - Reset auto level matrix
M323 S0 P1  ; M323 S0/S1  - Enable disable distortion correction P0 = not permanent, P1 = permanent = default
G33 R0      ; G33 R0      - Resets distortion matrix to 0
G131        ; G131        - Set extruder offset position to 0 - needed for calibration with G132
;
G1 Z112
@pause Get ready for X or Tower A
M99 S10 X0
@pause Done
@pause Get ready for Y or Tower B
M99 S10 Y0
@pause Done
@pause Get ready for Z or Tower C
M99 S10 Z0  ; M99  - M99 S<delayInSec> X0 Y0 Z0 - Disable motors for S seconds (default 10) for given axis.
@pause Done
;
G132 S1     ; G132 - calibrate endstop positions. Call this, after calling G131 and after centering the extruder holder.
;
