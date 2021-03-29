class visitor {
  String name;
  int number;
  visitor({this.name, this.number});
}

void main() {
  visitor vishal = new visitor(name: "vikas", number: 444446);
  print(vishal.name);
}
