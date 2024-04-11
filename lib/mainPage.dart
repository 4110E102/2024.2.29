import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter_constraintlayout/flutter_constraintlayout.dart';
import 'Page1.dart';

List<String> itemName =['簡介','設定','其他','網路'];

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
      home: const mainPage(title: 'Flutter Demo Home Page'),
    );
  }
}
class mainPage extends StatefulWidget {
  const mainPage({super.key, required this.title});
  final String title;

  @override
  State<mainPage> createState() => _mainPageState();
}
class _mainPageState extends State<mainPage> {
  int _counter = 0;

  void _incrementCounter() {
    setState(() {
      _counter++;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme
            .of(context)
            .colorScheme
            .inversePrimary,
        title: const Text ("4110E102 林彩融"),
      ),
      body: ConstraintLayout(
        children: [
          ...constraintGrid(
              id: ConstraintId('grid'),
              left: parent.left,
              top: parent.top,
              itemCount: 4,
              columnCount: 2,
              itemSize: 150,
              itemBuilder: (index, _, __) {
                return Container(
                  child: InkWell(
                    onTap: () {
                      print('你按了第$index');
                      if (index==0){
                        Navigator.push(
                          context,
                          MaterialPageRoute(builder: (context) => const page1()),
                        );
                      }
                    },

                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: <Widget>[
                        Image.asset('assets/images/menu$index.png', scale: 4.0, fit: BoxFit.scaleDown,),
                        Text(itemName[index], style: TextStyle(fontSize: 15)),
                      ],
                    ),
                  ),
                );
              },
              itemMarginBuilder: (index, _, __) {
                return const EdgeInsets.only(
                  left: 10,
                  top: 10,
                );
              }
          ),
        ],
      ),
    );
  }
}





