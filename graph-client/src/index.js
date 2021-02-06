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
    let matches = event.data.match(/\,(.*?)\]/)
    let data = matches[1]
    const pid = JSON.parse(data);

    let time = new Date();

    let update = {
      x:  [[time]],
      y: [[pid.steering_angle]]
    }

    Plotly.extendTraces('graph', update, [0])
};

ws.onclose = function() {
  console.info("PID Controller Client socket closing...")
  // websocket is closed.
  // window.clearInterval(request_data_interval)
};



function rand() {
  return Math.random()*(1.0-(-1.0)) + (-1.0)
}

var time = new Date();

var data = [{
  x: [time],
  y: [rand()],
  mode: 'lines',
  name: 'Steering angle',
  line: {color: '#80CAF6'}
}]


var layout = {
  showlegend: true,
  legend: {
    x: 1.05
  },
  title: {
    text: "PID Controller response",
  },
  xaxis: {
    showgrid: true,
    zeroline: true,
    showline: true,
    mirror: 'ticks',
    gridcolor: '#bdbdbd',
    gridwidth: 2,
    zerolinecolor: '#969696',
    zerolinewidth: 4,
    linecolor: '#636363',
    linewidth: 6
  },
  yaxis: {
    range: [-1.5, 1.5],
    showgrid: true,
    zeroline: true,
    showline: true,
    mirror: 'ticks',
    gridcolor: '#bdbdbd',
    gridwidth: 2,
    zerolinecolor: '#969696',
    zerolinewidth: 4,
    linecolor: '#636363',
    linewidth: 6
  }
};

Plotly.newPlot('graph', data, layout);