<?php

$conn = pg_connect("host=localhost dbname=coba1 user=postgres password=fitri");
if ($conn) {
  echo 'Connection attempt success.';
} else {
  echo 'Connection attempt failed.';
}
$waterLevel = $_GET['data1'];
$wl1 = $_GET['data2'];
$wl2 = $_GET['data3'];
$wl3 = $_GET['data4'];
$suhu = $_GET['data5'];
$suhu1 = $_GET['data6'];
$suhu2 = $_GET['data7'];
$suhu3 = $_GET['data8'];
$kelembaban = $_GET['data9'];
$kelembaban1 = $_GET['data10'];
$kelembaban2 = $_GET['data11'];
$kelembaban3 = $_GET['data12'];
$ph = $_GET['data13'];
$ph1 = $_GET['data14'];
$ph2 = $_GET['data15'];
$ph3 = $_GET['data16'];
$lux_conversion = $_GET['data17'];
$lux1 = $_GET['data18'];
$lux2 = $_GET['data19'];
$lux3 = $_GET['data20'];
$defuzzy_pompa = $_GET['data21'];
$defuzzy_up = $_GET['data22'];
$defuzzy_down = $_GET['data23'];
$status_pompa = $_GET['data24'];
$status_pompa_ph_up = $_GET['data25'];
$status_pompa_ph_down = $_GET['data26'];

$sql = "INSERT INTO jarak(jarak)
VALUES ('$waterLevel');";

if (pg_query($conn, $sql)) {
  echo "New record created successfully";
} 
else {
  echo "Error: " . $sql;
}

$sql = "INSERT INTO jarak1(jarak1)
VALUES ('$wl1');";

if (pg_query($conn, $sql)) {
  echo "New record created successfully";
} 
else {
  echo "Error: " . $sql;
}

$sql = "INSERT INTO jarak2(jarak2)
VALUES ('$wl2');";

if (pg_query($conn, $sql)) {
  echo "New record created successfully";
} 
else {
  echo "Error: " . $sql;
}

$sql = "INSERT INTO jarak3(jarak3)
VALUES ('$wl3');";

if (pg_query($conn, $sql)) {
  echo "New record created successfully";
} 
else {
  echo "Error: " . $sql;
}

$sql = "INSERT INTO suhu(suhu)
VALUES ('$suhu');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO suhu1(suhu1)
VALUES ('$suhu1');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO suhu2(suhu2)
VALUES ('$suhu2');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO suhu3(suhu3)
VALUES ('$suhu3');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO kelembaban(kelembaban)
VALUES ('$kelembaban');";

if (pg_query($conn, $sql)) {
  echo "New record created successfully";
} 
else {
  echo "Error: " . $sql;
}

$sql = "INSERT INTO kelembaban1(kelembaban1)
VALUES ('$kelembaban1');";

if (pg_query($conn, $sql)) {
  echo "New record created successfully";
} 
else {
  echo "Error: " . $sql;
}

$sql = "INSERT INTO kelembaban2(kelembaban2)
VALUES ('$kelembaban2');";

if (pg_query($conn, $sql)) {
  echo "New record created successfully";
} 
else {
  echo "Error: " . $sql;
}

$sql = "INSERT INTO kelembaban3(kelembaban3)
VALUES ('$kelembaban3');";

if (pg_query($conn, $sql)) {
  echo "New record created successfully";
} 
else {
  echo "Error: " . $sql;
}

$sql = "INSERT INTO ph(ph)
VALUES ('$ph');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO ph1(ph1)
VALUES ('$ph1');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO ph2(ph2)
VALUES ('$ph2');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO ph3(ph3)
VALUES ('$ph3');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO cahaya(cahaya)
VALUES ('$lux_conversion');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO cahaya1(cahaya1)
VALUES ('$lux1');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO cahaya2(cahaya2)
VALUES ('$lux2');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO cahaya3(cahaya3)
VALUES ('$lux3');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

$sql = "INSERT INTO fuzzy(defuzzypompa, defuzzyup, defuzzydown, msgpompaair, msgpompaup, msgpompadown)
VALUES ('$defuzzy_pompa', '$defuzzy_up', '$defuzzy_down', '$status_pompa', '$status_pompa_ph_up', '$status_pompa_ph_down');";

if (pg_query($conn, $sql)) {
    echo "New record created successfully";
} 
else {
    echo "Error: " . $sql;
}

function test_input($data) {
$data = trim($data);
$data = stripslashes($data);
$data = htmlspecialchars($data);
return $data;
}