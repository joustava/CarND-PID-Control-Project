import classes from './index.css';
import Plotly from 'plotly.js-dist'
const WebSocket = require('isomorphic-ws');

 
/**
 * Create a socket client connecting to the PID Controller.
 * 
 * This client socket receives broadcasts from the socket server only
 * on simulator updates.
 */
const ws = new WebSocket("ws://localhost:4567/")

ws.onopen = function() {
  console.info("PID Controller Client socket opened...")
  // Web Socket is connected, send data using send()
  // ws.send("Waiting for PID controller data");
  // request_data_interval = window.setInterval(requestData, 50);
}

ws.onmessage = function (event) { 
    const data = JSON.parse(event.data);

    console.log(data);

    // let samples = {
    //     x: data.x, 
    //     y: data.y, 
    //     type: 'scatter',
    // };
    // Plotly.newPlot('sine-graph', [samples]);
};

ws.onclose = function() {
  console.info("PID Controller Client socket closing...")
  // websocket is closed.
  // window.clearInterval(request_data_interval)
};
