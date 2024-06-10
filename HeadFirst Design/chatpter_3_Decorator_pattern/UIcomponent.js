class UIComponents {
    constructor(){

    }
    render(){
        throw new Error('Please OverRide this....');
    }
    setStyle(){
        throw new Error(`Please OverRide this Style function...`);
    }
}

class ButtonUI extends UIComponents {
    constructor(text){
        super();
        this.text = text;
        this.style = '';
    }
    render(){
        const style = this.style;
        this.style = '';
        return `<button style="${style}">${this.text}</button>`;
    }
    setStyle(style){
        this.style += style;
    }
}

class TextUI extends UIComponents {
    constructor(text){
        super();
        this.text = text;
        this.style = '';
    }
    render(){
        const style = this.style;
        this.style = '';
        return `<p style="${style}"> ${this.text} </p>`;
    }
    setStyle(style){
        this.style += style;
    }
}

class UIDecorator extends UIComponents {
    constructor(){}
    render(){
        throw new Error('Please OverRide UIDecorator render...')
    }
    setStyle(){
        throw new Error(`Please OverRide Style for Decorator...`);
    }
}

class BorderUI extends UIComponents {
    constructor(UIComponents){
        super();
        this.uiComponents = UIComponents;
        this.style = `border: 2px solid black; background-color: white; color: black; padding: 14px 28px; font-size: 16px; cursor: pointer;`;
    }
    render(){
       this.uiComponents.setStyle(this.style);
       return this.uiComponents.render();
    }
    setStyle(style){
        this.uiComponents.setStyle(style);
    }
}

class UnderlineUI extends UIComponents {
    constructor(UIComponents){
        super();
        this.uiComponents = UIComponents;
        this.style = `text-decoration: underline;`;
    }
    render(){
       this.uiComponents.setStyle(this.style);
       return this.uiComponents.render();
    }
    setStyle(style){
        this.uiComponents.setStyle(style);
    }
}
const textUI = new TextUI(`Testing Text Component`);
console.log(textUI.render());
const underTextUI = new UnderlineUI(textUI);
console.log(underTextUI.render());
const borderUnderlineTextUi = new BorderUI(underTextUI);
console.log(borderUnderlineTextUi.render());