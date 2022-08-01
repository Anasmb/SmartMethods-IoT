<?php

$conn = mysqli_connect("localhost", "root", '', "esp32");

if (mysqli_connect_errno()) {
    die('Unable to connect to database ' . mysqli_connect_error());
}

header("Access-Control-Allow-Origin: *");
$qry = $conn->prepare("SELECT * FROM dht ORDER BY ID DESC LIMIT 1");

$qry->execute();
$qry->bind_result($id, $temperature, $humidity, $addedOnData);

$columns = array();

while ($qry->fetch()) {
    $temp = array();
    $temp['Temperature'] = $temperature;
    $temp['Humidity'] = $humidity;
    $temp['AddedOnData'] = $addedOnData;
    array_push($columns, $temp);
}

echo json_encode($columns);
