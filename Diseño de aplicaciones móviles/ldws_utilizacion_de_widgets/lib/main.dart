import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('LDSW: Utilización de widgets'),
        ),
        body: const MyWidgetPage(),
      ),
    );
  }
}

class MyWidgetPage extends StatelessWidget {
  const MyWidgetPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.start,
      children: <Widget>[
        const Text(
          'Este es un Text widget',
          style: TextStyle(fontSize: 24),
        ),
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceAround,
          children: const <Widget>[
            Icon(Icons.star, color: Colors.yellow),
            Icon(Icons.star, color: Colors.blue),
            Icon(Icons.star, color: Colors.red),
          ],
        ),
        const SizedBox(height: 20),
        Container(
          width: 100,
          height: 100,
          color: Colors.amber,
          child: const Center(
            child: Text('Container'),
          ),
        ),
        const SizedBox(height: 20),
        Stack(
          alignment: Alignment.center,
          children: <Widget>[
            Container(
              width: 150,
              height: 150,
              color: Colors.purple,
            ),
            const Text(
              'Stack Widget',
              style: TextStyle(color: Colors.white, fontSize: 16),
            ),
          ],
        ),
        const Spacer(),
        const Text(
          'Realizado: Juan Pablo Ramirez :)',
          style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
        ),
      ],
    );
  }
}
