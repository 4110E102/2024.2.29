
<!DOCTYPE html>
<html lang = "en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>String Replace in PHP</title>
</head>
<body>
    <h1>PHP 字串替換工具</h1>
    <form method="post">
        <label for="subject">原始字串:</label>
        <input type="text" id="subject" name="subjecttxt" required><br><br>
        <label for="search">查找字串:</label>
        <input type="text" id="search" name="searchtxt" required><br><br>
        <label for="replace">替換成:</label>
        <input type="text" id="replace" name="replacetxt" required><br><br>
        <button type="submit" name="submit">替換字串</button>
    </form>
    <?php
        if ($_SERVER["REQUEST_METHOD"] == " POST" && isset($_POST['submit'])) {
           if (isset($_POST['searchtxt']) && isset($_POST['replacetxt']) && isset($_POST['subjecttxt'])){
              $search_s = $_POST['searchtxt'];
              $replace_s = $_POST['replacetxt'];
              $subject_s = $_POST['subjecttxt'];
              $replacedText = str_replace($search_s, $replace_s, $subject_s);
              echo "<p>原始字串: " . htmlspecialchars($subject_s) . "</p>";
              echo "<p>被取代的字串是: " . htmlspecialchars($replacedText) . "</p>";
           } else {
              echo "<p>請填寫所有欄位。</p>";
           }
        }
    ?>
</body>
</html>