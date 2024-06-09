class Text {

    // we can use Getter and Setter for this but for now lets go simple
    constructor(text){
        this.text = text;
    }
    
    getText(){
        return this.text;
    }

}


class Bold {
    constructor(Text){
        this.text = Text.getText();
    }

    getText(){
        return `${this.text} + bold`;
    }
}

class Italic {
    constructor(Text){
        this.text = Text.getText();
    }
    
    getText(){
        return `${this.text} + italic`;
    }
}

class Underline {
    constructor(Text){
        this.text = Text.getText();
    }

    getText(){
        return `${this.text} + underline`;
    }
}

const text = new Text("Abhishek Zade");
const BoldText = new Bold(text);
console.log(BoldText.getText());
const ItalicText = new Italic(text);
console.log(ItalicText.getText());
const BoldItalicText = new Bold(ItalicText);
console.log(BoldItalicText.getText());
const underline = new Underline(BoldItalicText);
console.log(underline.getText());