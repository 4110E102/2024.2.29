<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CSV 文件上傳與顯示</title>
</head>
<body>
    <h1>上傳並顯示 CSV 文件內容</h1>
    <form action="" method="post" enctype="multipart/form-data">
        <label for="file">選擇 CSV 文件：</label>
        <input type="file" id="file" name="file" accept=".csv" required><br><br>
        <button type="submit" name="submit">上傳並顯示</button>
    </form>
    <?php
        if ($_SERVER(["REQUEST_METHOD"] == "POST" && isset($_FILES["file"]) && isset($_POST["submit"])) {
            $file = $_FILES["file"];
	    if ($file["error"] != UPLOAD_ERR_OK) {
                echo "<p>文件上傳失敗。</p>";
                exit;
            } 
            $fileType = pathinfo($file["name"],PATHINFO_EXTENSION);
            if ($fileType != "csv"){
                echo "<p>請上傳一個 CSV 文件。</p>";
                exit;
            }
            
            $filePath = $file["tmp_name"];
            if (($handle = fopen($filePath, "r")) !== false) {
                echo "<h2>文件內容:</h2>";
                echo "<table border='1'>";
            if (($hander = fgetcsv($handle,1000,",")) !== false){
                echo "<tr>";
                foreach ($header as $col) {
                    echo "<th>" . htmlspecialchars($col) . "</th>";
                }
                echo "</th>";
            }
            while (($data = fgetcsv($handle, 1000, ",")) !== false){
                echo "<tr>";
                foreach ($data as $col){
                    echo "<td>" . htmlspecialchars($col) . "</td>";
                }
                echo "</tr>";
            }
            echo "</table>";
            fclose($handle);
        } else {
            echo "<p>等待輸入! </p>";
        }
        ?>
</body>
</html>
