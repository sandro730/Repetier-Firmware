;
; Configure Auto Level Rotation
;
G28         ; Home
;           ; M320 S<0/1> - Activate auto level, S1 stores it in eeprom
M321 S1     ; M321 S<0/1> - Deactivate auto level, S1 stores it in eeprom
M322        ; M322        - Reset auto level matrix
;
; M320    ; Activate auto level temporarily
; M320 S2 ; Activate auto level permanently
; M321    ; Deactivate autolevel temporarily
; M321 S2 ; Deactivate auto level permanently
; M322    ; Reset auto level matrix
; M322 S3 ; Reset auto level matrix permanently
;
M323 S0 P1  ; M323 S0/S1  - Enable disable distortion correction P0 = not permanent, P1 = permanent = default
G33 R0      ; G33 R0      - Resets distortion matrix to 0
;
G28         ; Home
;
G1 X0 Y0 Z30  ; Move to center Z=30
;
G32 S2
;
M323        ; M323 ; Show if correction is enabled
;