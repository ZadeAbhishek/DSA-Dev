/**
 * 
 */
class Notifier {
    send(msg){
      throw new Error('Please OverSide The SEND function');
    }
}

class EmailNotifier extends Notifier {
    send(msg){
        console.log(`Email :: ${msg}`);
    }
}

class SmsNotifier extends Notifier {
    send(msg){
      console.log(`SMS :: ${msg}`);
    }
}

class NotifierFilterDecorator extends Notifier {
    constructor(notifier){
        super(); // we are using super so when we inherit this class constructor will autimatically have reference of thid class
        this.notifier = notifier;
    }
    send(msg){
        this.notifier.send(msg);
    }
}

class LoggingFilter extends NotifierFilterDecorator {
    send(msg){
        console.log(`Applied Logging Filter on ${msg}`);
        super.send(msg);
    }
}

class filterNotification extends NotifierFilterDecorator {
    send(msg){
        if(this.filter(msg)){
            console.log(`msg Filtered`);
            super.send(msg);
        }
        else {
            console.log(`msg Filter out`);
        }
    }

    filter(message) {
        return message && message.trim().length > 0;
    }
}

const emailNotifier = new EmailNotifier();
const loggingFilter = new filterNotification(emailNotifier);
loggingFilter.send("This is Email");