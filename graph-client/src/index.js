import classes from './index.css';
import Plotly from 'plotly.js-dist'
const WebSocket = require('isomorphic-ws');

/**
 * Create a socket client connecting to the PID Controller.
 * 
 * This client socket receives broadcasts from the socket server only
 * on simulator updates.
 */
const ws = new WebSocket("ws://localhost:4567/");

ws.onopen = function() {
  console.info("PID Controller Client socket opened...");
}

ws.onmessage = function (event) {
    let matches = event.data.match(/\,(.*?)\]/);
    let data = matches[1];
    const pid = JSON.parse(data);

    let time = new Date();

    let update = {
      x: [[time], [time]],
      y: [[pid.steering_angle], [pid.throttle]]
    }

    Plotly.extendTraces('graph', update, [0, 1]);
}

ws.onclose = function() {
  console.info("PID Controller Client socket closing...");
}

function rand() {
  return Math.random()*(1.0-(-1.0)) + (-1.0);
}

var time = new Date();

var data = [
  {
    x: [time],
    y: [0],
    mode: 'lines',
    name: 'Steering angle',
    line: {color: '#80CAF6'}
  },
  {
    x: [time],
    y: [0],
    mode: 'lines',
    name: 'Throttle',
    line: {color: '#ad1f40'}
  }
]


var layout = {
  showlegend: true,
  legend: {
    x: 1,
    xanchor: 'right',
    y: 1
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