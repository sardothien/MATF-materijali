CREATE TABLE DA.PRAKSA (
    INDEKS          INTEGER NOT NULL PRIMARY KEY,
    POENI_STUDIJE   REAL    NOT NULL,
    POENI_TEST      REAL    NOT NULL,
    FOREIGN KEY     (INDEKS)
        REFERENCES  DA.DOSIJE
);
