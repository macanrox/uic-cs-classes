CREATE TABLE airline (
	name VARCHAR(40) PRIMARY KEY NOT NULL,
	address VARCHAR(40),
	phoneNumber INT(10)
);

CREATE TABLE airplanes (
	planeID VARCHAR(12) PRIMARY KEY NOT NULL,
	weight DOUBLE NULL,
);

CREATE TABLE gates (
	gateNumber BIGINT(12) PRIMARY KEY NOT NULL,
	fee DECIMAL(5, 2) NULL,
	gateID VARCHAR(4) NULL,
	terminal VARCHAR(12) NULL,
	rentStatus BOOLEAN NOT NULL
);

CREATE TABLE passenger_airplanes (
	planeID VARCHAR(12) PRIMARY KEY NOT NULL,
	numSeats INT NULL,
	maxPassengers INT NULL,
	FOREIGN KEY planeID REFERENCES airplanes(planeID)
);

CREATE TABLE cargo_airplanes (
	planeID VARCHAR(12) PRIMARY KEY NOT NULL,
	maxCargoWeight DOUBLE NULL,
	FOREIGN KEY planeID REFERENCES airplanes(planeID)
);

CREATE TABLE passenger_runway (
	pRunwayCode VARCHAR(40) PRIMARY KEY NOT NULL,
	length DOUBLE NULL,
	landTime TIMESTAMP NOT NULL
);

CREATE TABLE cargo_runway (
	cRunwayCode VARCHAR(40) PRIMARY KEY NOT NULL,
	length DOUBLE NULL,
	landTime TIMESTAMP NOT NULL
);

CREATE TABLE hangers (
	hangerID VARCHAR(40) PRIMARY KEY NOT NULL,
	planeID VARCHAR(12) NOT NULL,
	area DOUBLE NULL,
	maxPlanes INT NULL,
	doorSize DOUBLE NULL,
	FOREIGN KEY planeID REFERENCES airplanes(planeID)
);

CREATE TABLE passenger_airline (
	name VARCHAR(40) PRIMARY KEY NOT NULL,
	planeID VARCHAR(12) NOT NULL,
	pRunwayCode VARCHAR(40) NOT NULL,
	gateNumber BIGINT(12) NOT NULL,
	FOREIGN KEY name REFERENCES airline(name),
	FOREIGN KEY planeID REFERENCES airplanes(planeID),
	FOREIGN KEY pRunwayCode REFERENCES passenger_runway(pRunwayCode),
	FOREIGN KEY gateNumber REFERENCES gates(gateNumber)
);

CREATE TABLE cargo_airline (
	name VARCHAR(40) PRIMARY KEY NOT NULL,
	planeID VARCHAR(12) NOT NULL,
	cRunwayCode VARCHAR(40) NOT NULL,
	hangerID VARCHAR(40) NOT NULL,
	FOREIGN KEY name REFERENCES airline(name),
	FOREIGN KEY planeID REFERENCES airplanes(planeID),
	FOREIGN KEY cRunwayCode REFERENCES cargo_runway(pRunwayCode),
	FOREIGN KEY hangeID REFERENCES hangers(hangerID)
);
