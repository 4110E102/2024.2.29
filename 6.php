<!DOCTYPE html>
<html>
<body>

<?php
$x = 5;
$y = 10;

 function myTest(){
    $GLOBALS['y'] = $GLOBALS['x'] + $GLOBALS['y'];
}
myTest();

echo "Variable \$y IS ?" . $y;
echo "<p>variable \$GLOBALS['y'] is". $GLOBALS['y'];

?>
</body>
</html>