<?php
 $dept=str_replace("'","''",$_REQUEST['dept']);

 $db_host = "localhost";
 $db_name = "ksu_database";
 $db_table = "ksu_cstd_table";
 $db_user = "root";
 $db_password = "";

 // 連結檢測
 $conn = mysqli_connect($db_host, $db_user, $db_password);
 if(empty($conn)){
    print mysqli_error ($conn);
    die ("無法對資料庫連線!");
    exit;
}
if(!mysqli_select_db( $conn, $db_name)){
    die("資料庫不存在!");
    exit;
}
//字型設定
mysqli_set_charset($conn, 'utf8');
echo "ksu_std_table 學生於各系人數顯示如下:". "<br/><br/>";
$result = mysqli_query($conn,
                       "SELECT ksu_std_name, ksu_std_grade
                       FROM ksu_std_table where ksu_std_department = '$dept'
                       order by ksu_std_grade");
echo "<table border='1'>
<tr>
  <th> 學生姓名 </th> <th>學生成績 </th> <th>備註 </th>
</tr>";

//使用 mysqli_fetch_array() 取回資料庫資料
$row_num=0;//
$row_num_ex=0;
while($row = mysqli_fetch_array($result))
{
  echo "<tr>";
  echo "<td>" . $row['ksu_std_name'] . "</td>";
  echo "<td>" . $row['ksu_std_grade'] .  "</td>";
  
  if( $row['ksu_std_grade'] >=80)
  {    echo "<td style=\"background-color:yellow\"> "."優" .  "</td>";
      $row_num_ex=$row_num_ex+1;
  }
  else
  {    echo "<td>" . "" .  "</td>";
  }
  echo "</tr>";
  $row_num = $row_num+1;//
}
echo "</table>";
echo $row_num . " records found"."<br/><br/>";//
echo $row_num_ex . " 個學生優"."<br/><br/>";
?>
<form enctype="multipart/form-data" method="post" action="ksu_select6.html">
<input type="submit" name="sub" value="返回"/>
</form>