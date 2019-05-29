--===============================================
-- SQL
--===============================================

-- supprimer une table
DROP TABLE Persons;

-- créer une table
CREATE TABLE Persons (
PersonID INT,
LastName VARCHAR(255),
Address VARCHAR(255),
City VARCHAR(255));

-- insérer une ligne de données dans une table
INSERT INTO Persons (PersonID, LastName, Address, City) VALUES
(60, "LastName6", "Address6", "City6");

-- insérer plusieurs lignes de données dans une table
INSERT INTO Persons (PersonID, LastName, Address, City) VALUES
(10, "LastName1", "Address1", "City1"),
(20, "LastName2", "Address2", "City2"),
(30, "LastName3", "Address1", "City3"),
(40, "LastName4", "Address3", "City4"),
(50, "LastName5", "Address4", "City5"); 

-- afficher des données dans une table
SELECT PersonID, LastName, Address, City
FROM Persons; 

-- modifier une ligne de données dans une table











