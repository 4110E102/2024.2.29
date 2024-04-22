<?php

    $numbers =array(16, 62, 53, 54, 55);
    $colors = [
        "red" => "紅色",
        "green" => "綠色",
        "blue" =>"藍色"
    ];
    echo "第一個數字: " . $numbers[0] . "<br>";
    echo "顏色'green': " . $colors['green'] . "<br><br>";

    echo "所有數字:<br><br>";
    foreach ($numbers as $number) {
        echo $number . "<br>";
    }
    echo "<br>所有顏色:<br>";
    foreach ($colors as $key => $color) {
        echo $key . ":" .$color . "<br>";
    }
?>