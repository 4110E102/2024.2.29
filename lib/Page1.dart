import 'dart:async';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class page1 extends StatefulWidget {
  const page1({super.key});
@override
createState()=> pageHome1();

}

int counter = 200;
var sTimer;
class pageHome1 extends State<page1>{
  @override
  void initState(){
    counter = 200;
    startTimer();
  }

  void startTimer(){
    sTimer = Timer.periodic(const Duration(seconds: 1),(timer){
      if (counter<195){
        Navigator.of(context).pop();
      }
      setState((){
        counter--;
      });
    });
  }

  @override
  Widget build(BuildContext context){
    return Scaffold(
      appBar: AppBar(
        title:Text('簡介'),
      ),
      body: Container(
        padding:const EdgeInsets.only(left:10.0,right:10.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          children: <Widget>[
            Text(
              '時間設定',style: const TextStyle(fontSize: 24, color: Colors.blue,),
            ),
            Text(
              '$counter',style: const TextStyle(fontSize: 24, color: Colors.red,),
            )
          ],
        ),
      ),
    );
  }
}

