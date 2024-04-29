<?php
   $text = "Hello, welcome to PHP world!";
   $length = strlen($text);
   echo "長度是: " . $length . "<br>";
   $replacedText = str_replace("PHP", "programming", $text);
   echo "被取代的字串是: " . $replacedText . "<br>";
   $substring = substr($text, 7, 7);
   echo "所找到的子字串是: " . $substring . "<br>";
?>