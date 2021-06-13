const mongoose = require('mongoose');
const Dessert = require('../models/dessertModel');

module.exports.getAllDesserts = async (req, res, next) => {

    try {
        const desserts = await Dessert.find({}).exec();
        if(!desserts) {
            res.status(500).json();
        }
        else {
            res.status(200).json(desserts);
        }

    } catch(err) {
        next(err);
    }
};

module.exports.getDessertsByCriterion = async (req, res, next) => {

    const criterion = req.params.criterion;    

    try {
        let desserts;
        if(criterion === "lowcalorie") {
            desserts = await Dessert.find({ nutrition: {$lt: 400} }).exec();
        }
        else if(criterion === "glutenfree") { 
            desserts = await Dessert.find({ glutenFree: true }).exec();
        }
        else {
            res.status(500).json({ message: "wrong criterion" });
            return ;
        }
        
        if(!desserts) 
            res.status(500).json(null);
        else
            res.status(200).json(desserts);

    } catch(err) {
        next(err);
    }
};

module.exports.postNewDessert = async (req, res, next) => {

    const name = req.body.name;
    const description = req.body.description;
    const complexity = req.body.complexity;
    const nutrition = req.body.nutrition;
    const glutenFree = req.body.glutenFree;

    if(!name || !description || !complexity || !nutrition || glutenFree === undefined) {
        res.status(500).json(null);
        return ;
    }

    try {
        
        const newDessert = new Dessert({
            _id: new mongoose.Types.ObjectId(),
            name: name,
            description: description,
            complexity: complexity,
            nutrition: nutrition,
            glutenFree: glutenFree
        });

        await newDessert.save();

        res.status(200).json(newDessert);

    } catch(err) {
        next(err);
    }
}