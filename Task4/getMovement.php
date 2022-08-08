<?php
//© Copyright 2022 - Written By Anasmb 
$conn = mysqli_connect("localhost", "root", '', "esp32");

if (mysqli_connect_errno()) {
    die('Unable to connect to database ' . mysqli_connect_error());
}

header("Access-Control-Allow-Origin: *");
$qry = $conn->prepare("SELECT * FROM movement ORDER BY ID DESC LIMIT 1");

$qry->execute();
$qry->bind_result($id, $direction, $duration, $dateTime);

$columns = array();

while ($qry->fetch()) {
    $temp = array();
    $temp['ID'] = $id;
    $temp['Direction'] = $direction;
    $temp['Duration'] = $duration;
    array_push($columns, $temp);
}

echo json_encode($columns);
