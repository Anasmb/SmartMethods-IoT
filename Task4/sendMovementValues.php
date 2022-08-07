<?php

$conn = mysqli_connect("localhost", "root", '', "esp32");

if (mysqli_connect_errno()) {
    die('Unable to connect to database ' . mysqli_connect_error());
}

$direction = $_POST['direction'];
$duration = $_POST['duration'];

$qry = $conn->prepare("INSERT INTO movement (Direction, Duration) VALUES ('" . $direction . "','" . $duration . "')");

if ($qry->execute()) {
    echo "Add Success";
} else {
    echo "Add Failed";
}
