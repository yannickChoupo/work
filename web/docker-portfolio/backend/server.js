const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const cors = require('cors');
const socketIO = require('socket.io');
const http = require('http');

const app = express();
app.use(
    bodyParser.urlencoded({ extended: false })
);
app.use(bodyParser.json());
app.use(cors());

app.get('/',(req,res) => {
    res.send('Portfolio server is running.');
});
