const mongoose = require('mongoose');
const Meteo = require('../models/meteoModel');

module.exports.getAllMeteos = async (req, res, next) => {

    try {
        const meteos = await Meteo.find({}).exec();
        if(!meteos){
            res.status(500).json();
        }
        else {
            res.status(200).json(meteos);
        }

    } catch(err) {
        next(err);
    }
};

module.exports.getCityMeteos = async (req, res, next) => {

    const city = req.params.city;
    
    try {
        const meteo = await Meteo.find({ city: city }).exec();
        if(!meteo){ 
            res.status(500).json(null);
        }
        else {
            res.status(200).json(meteo);
        }

    } catch(err) {
        next(err);
    }
};

module.exports.putChangeTemperatures = async (req, res, next) => {

    const city = req.body.city;
    const newTemperatures = req.body.temperatures;
    if(!city || !newTemperatures) {
        res.status(500).json({ message: "city or temperatures missing" });
        return ;
    }

    try {
        const meteo = await Meteo.find({ city: city }).exec();
        meteo[0].temperatures = newTemperatures;
        await meteo[0].save();

        res.status(200).json({ message: "temperatures changed" });

    } catch(err) {
        next(err);
    }
};