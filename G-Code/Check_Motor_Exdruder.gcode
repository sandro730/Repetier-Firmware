;
; Chech Motor Extrider
;
G28 
G1 Z100 
M302 S1 
G1 E100
; Motore estrusore si muove di poco poi si ferma.
G1 E100
; Motore non si muove
G1 E-100
; Motore estrusore si muove di poco poi si ferma.
G1 E-100
; Motore non si muove
;