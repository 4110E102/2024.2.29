import 'package:flu02/mainPage.dart';
import 'package:flutter/material.dart';
import 'package:flutter_constraintlayout/flutter_constraintlayout.dart';

String userId = '';
String userPw = '';
void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});



  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;

  void _incrementCounter() {
    setState(() {

      _counter++;
    });
  }

  @override
  Widget build(BuildContext context) {
    ConstraintId dividerTOP = ConstraintId('dividerTOP');
    ConstraintId guidelineV = ConstraintId('guidelineV');
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: const Text ("4110E102 林彩融"),
      ),
      body: ConstraintLayout(
          children: [
            /* 輸入元件------------------------------------------*/
            Text(
              '帳號', style: const TextStyle(fontSize: 24, color: Colors.blueAccent,),
            ).applyConstraint(
              top: dividerTOP.bottom,
              right: guidelineV.left,
              margin: const EdgeInsets.only(
                top: 50,
                right: 20,
              ),
            ),
            SizedBox(
              width: 120.0,
              height: 40.0,
              child:
              TextField(
                onChanged: (newValue) {
                  userId = newValue;
                },
                style: const TextStyle(fontSize: 14,),
                decoration: const InputDecoration(
                  fillColor: Colors.lightGreenAccent,
                  border: OutlineInputBorder(borderRadius: BorderRadius.all(Radius.circular(2),),
                  ),
                ),
              ),
            ).applyConstraint(
              top: dividerTOP.bottom,
              left: parent.center,
              margin: const EdgeInsets.only(
                top: 50,left: -40,
              ),
            ),




            Text(
              '密碼', style: const TextStyle(fontSize: 24, color: Colors.pinkAccent,),
            ).applyConstraint(
              top: dividerTOP.bottom,
              right: guidelineV.left,
              margin: const EdgeInsets.only(
                top: 100,
                right: 20,
              ),
            ),
            SizedBox(
              width: 120.0,
              height: 40.0,
              child:
              TextField(
                onChanged: (newValue){
                  userPw = newValue;
                  print("==="+userPw);
                },
                style: const TextStyle(fontSize: 14,),
                obscureText: true,
                //decoration: const InputDecoration(
                // fillColor: Colors.lightGreenAccent,
                //border: OutlineInputBorder(borderRadius: BorderRadius.all(Radius.circular(2),),
                // ),
                // ),
              ),
            ).applyConstraint(
              top: dividerTOP.bottom,
              left: parent.center,
              margin: const EdgeInsets.only(
                top: 100,left: -40,
              ),
            ),

            ElevatedButton(
              style: ElevatedButton.styleFrom(
                padding: const EdgeInsets.symmetric(horizontal: 40.0, vertical: 10.0),
                backgroundColor: Colors.teal,
                shape: const StadiumBorder(),
                elevation: 0,
              ),
              child: Text('登入', style: const TextStyle(fontSize: 18)),
              onPressed: () {
                if (userId == 'mary' && userPw == '123'){
                  Navigator.push(
                    context,
                    MaterialPageRoute(builder: (context) => const mainPage(title: '主畫面',)),
                  );
                  print('驗證正確 ...... 登入 ');
                }else {
                  print('驗證失敗 ?????');
                }
              },
            ).applyConstraint(
              top: dividerTOP.bottom,
              left: parent.center,
              margin: const EdgeInsets.only(
                top: 180,left: -45,
              ),
            ),


            Divider(
              color: Colors.black,
            ).applyConstraint(
                id: dividerTOP,
                top: parent.top,
                left: parent.left,
                margin: EdgeInsets.only(
                  top: MediaQuery.of(context).size.height * 0.1,
                )
            ),
            Guideline(
              id: guidelineV,
              horizontal: false,
              guidelinePercent: 0.3,
            ),
          ]

      ),
    );

  }
}
