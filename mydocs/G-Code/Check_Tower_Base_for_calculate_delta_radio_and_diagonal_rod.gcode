;
; Check height Z at the base of the towers.
; See website: : https://escher3d.com/pages/wizards/wizarddelta.php
;
G28         ; Home
;           ; M320 S<0/1> - Activate auto level, S1 stores it in eeprom
M321 S1     ; M321 S<0/1> - Deactivate auto level, S1 stores it in eeprom
M322        ; M322        - Reset auto level matrix
M323 S0 P1  ; M323 S0/S1  - Enable disable distortion correction P0 = not permanent, P1 = permanent = default
G33 R0      ; G33 R0      - Resets distortion matrix to 0
;
G1 X0       Y0   Z30  ; To Center
;
G1 X-121.80 Y-70.00   ; Towers X
G30
G1 X0       Y0   Z30  ; To Center
G30
G1 X121.80  Y70.00    ; Towers X
G30
;
G1 X0       Y0   Z30  ; To Center
;
G1 X121.8   Y-70      ; Tower Y
G30 
G1 X0       Y0   Z30  ; To Center
G30
G1 X-121.8  Y70       ; Tower Y
G30
;
G1 X0       Y0   Z30  ; To Center
;
G1 X0       Y140      ; Tower Z
G30
G1 X0       Y0   Z30  ; To Center
G30
G1 X0       Y-140      ; Tower Z
G30
;
G1 X0       Y0   Z30  ; To Center
;
; Z rilevate con valori teorici
;
; 18:04:39.338 : Z-probe:25.736 X:-121.80 Y:-70.00
; 18:04:43.500 : Z-probe:26.429 X:0.00 Y:0.00
; 18:04:47.694 : Z-probe:26.663 X:121.80 Y:70.00
; 
; 18:04:53.277 : Z-probe:26.049 X:121.80 Y:-70.00
; 18:04:57.446 : Z-probe:26.406 X:0.00 Y:0.00
; 18:05:01.527 : Z-probe:25.899 X:-121.80 Y:70.00
; 
; 18:05:07.133 : Z-probe:26.176 X:0.00 Y:140.00
; 18:05:11.263 : Z-probe:26.416 X:0.00 Y:0.00
; 18:05:15.325 : Z-probe:25.999 X:0.00 Y:-140.00
;