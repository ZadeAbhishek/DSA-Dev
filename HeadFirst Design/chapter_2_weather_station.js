class weatherData{
   
    constructor(){
     this.data = {
        temperature : 0,
        humidity : 0,
        pressure : 0,
     };
     this.observer = []; // we are defining array here
   }

   // Since we are having Display interface

   // registerObserver
   registerObserver(observer) {
       this.observer.push(observer);
   }

   // Remove Observer from this list 
   removeObserver(observer){
      this.observer.filter((o) => o.observer !== observer);
   }
   
   // notify all the Observers
   notifyObserver(){
     this.observer.forEach((ob) => ob.update(this.data));
   }
   

   // just call notify observers
   measureChanges(){
    this.notifyObserver();
   }

   // set the new update
   setMeasurements(temperature,humidity,pressure){
     this.data.humidity = humidity;
     this.data.temperature = temperature;
     this.data.pressure = pressure;
     this.measureChanges();
   }
}


class currentDisplay{
   constructor(weatherData){
    this.temperature;
    this.humidity;
    this.weatherData = weatherData;
    this.weatherData.registerObserver(this); // register this display when init
   }

   update({temperature,humidity,pressure}){
    this.temperature = temperature;
    this.humidity = humidity;
    this.display();
   }

   display(){
    console.log(`Temperature::${this.temperature} ::: Humidity::${this.humidity}`);
   }
}

// changes
class heatIndexDisplay{
    
    constructor(weatherData){
        this.temperature = 0;
        this.humidity = 0;
        this.weatherData = weatherData;
        this.heatIndex = 0;
        this.weatherData.registerObserver(this); // register this display when init
    }

    calculateIndex(){
        this.heatIndex = this.temperature * this.humidity * 0.23;
    }
    update({temperature,humidity,pressure}){
        this.temperature = temperature;
        this.humidity = humidity;
        this.calculateIndex();
        this.display();
    }
    display(){
        console.log(`HeatIndex :: ${this.heatIndex}`);
    }
}

class pressureDisplay{
    constructor(weatherData){
     this.pressure;
     this.weatherData = weatherData;
     this.weatherData.registerObserver(this); // register this display when init
    }
 
    update({pressure}){
     this.pressure = pressure;
     this.display();
    }
 
    display(){
     console.log(`Pressure :: ${this.pressure}`);
    }
 }


class weatherStation{
    constructor(){
        this.weatherData = new weatherData();
        this.currentDisplay = new currentDisplay(this.weatherData);
        this.heatIndexDisplay = new heatIndexDisplay(this.weatherData); // changes
        this.pressureDisplay = new pressureDisplay(this.weatherData);
    }

    getData(){
        this.weatherData.setMeasurements(1,2,8);
    }
}

const weatherstation = new weatherStation();
weatherstation.getData();
