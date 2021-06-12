const mongoose = require('mongoose');

const meteoSchema = mongoose.Schema({
    _id: mongoose.Types.ObjectId,
    city: {
        type: String,
        require: true
    },
    country: {
        type: String,
        require: true
    },
    temperatures: {
        type: [Number],
        require: true
    }
});

const meteoModel = mongoose.model('Meteo', meteoSchema);

module.exports = meteoModel;