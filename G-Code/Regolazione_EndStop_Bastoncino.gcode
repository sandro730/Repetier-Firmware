G28           ; Home
M322 S3       ; Reimposta la matrice di livello automatico in modo permanente
; Regolazione EndStop spostando i carrelli manualmente su
; riscontro con il bastoncino.
M321 S2       ; Disattiva il livello automatico in modo permanente
M323 S0 P1    ; Disattiva la correzione in modo permanente
G33 R0        ; Elimina mappa di distorsione
;
G131          ; Rimuovi qualsiasi offset estrusore
G1 Z20        ; Posiziona i carrelli in prossimit? delle lunghezza del riscontro
@pause Preparati per X
M99 X0 S10
@pause Fatto X
@pause Preparati per Y
M99 Y0 S10
@pause Fatto Y
@pause Preparati per Z
M99 Z0 S10    ; Toglie corrente al motore. Regola i cursori usando un bastoncino
@pause Fatto Z
G132 S1       ; Misura gli offset dei finecorsa della torre e negozi
;M320 S2      ; Attiva il livellamento automatico in modo permanente
;G32 S2       ; 3 misure, fissa la rotazione del letto e ripostiglio
;G33 S2       ; fissa la distorsione del letto e del ripostiglio
;M323 S1 P1   ;
;G1 X0 Y0 Z10


