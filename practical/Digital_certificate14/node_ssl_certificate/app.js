const express = require('express')
const https = require('https')
const path = require('path')
const fs = require('fs')
const res = require('express/lib/response')

const app = express()

app.use('/',(req, res, next) => {
    res.send('Hello from SSL Server')
})

const sslserver  = https.createServer({
    key: '',
    cert: '',
}, app)

sslserver.listen(3443, () => consle.log('Secure Server running on port 3443'))
