;
; Configure Distortion Correction
;
G28           ; Home
;             ; M320 S<0/1> - Activate auto level, S1 stores it in eeprom
M321 S1       ; M321 S<0/1> - Deactivate auto level, S1 stores it in eeprom
M322          ; M322        - Reset auto level matrix
;
; Switching distortion correction on/off
; M323 ; Show if correction is enabled
; M323 S0 ; Disable correction
; M323 S0 P1 ; Disable correction permanently
; M323 S1 ; Enable correction
; M323 S1 P1 ; Enable correction permanently
;
M323 S0 P1    ; M323 S0/S1  - Enable disable distortion correction P0 = not permanent, P1 = permanent = default
G33 R0        ; G33 R0      - Resets distortion matrix to 0
;
G28           ; Home
;
G1 X0 Y0 Z20  ; Move to center Z=20
;
; - G33 - Measure distortion map
; - G33 R0 - delete distortion map
; - G33 L0 - List distortion map
; - G33 X<xpos> Y<ypos> Z<newdistortioncorrection> - Set new distortion for nearest distortion point.
;
G33
;
G1 X0 Y0 Z20  ; Move to center Z=20
;
G33 L0
;
M323          ; M323 ; Show if correction is enabled
;
M323 S0 P1    ; M323 S0 P1 ; Disable correction permanently
;
M323          ; M323 ; Show if correction is enabled
;