<!DOCTYPE html>
<html>
<body>

 <?php
  $x = 5;

  function myTest() {
    echo "<p> mytest()-Variable x inside function is: $x</p>";
  }
  myTest();
  echo "<p>Variable x outside function is: $x</p>";
 ?>

</body>
</html>