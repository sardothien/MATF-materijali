const mongoose = require('mongoose');
const Payment = require('../models/payment');

module.exports.getPaymentByEmail = async (req, res, next) => {
    email = req.params.email;

    try {
        const payment = await Payment.find({ email: email }).exec();
        if(payment) {
            res.status(200).send(payment);
        }
        else {
            res.status(500).send(null);
        }

    } catch(error) {
        next(error);
    }
}

module.exports.getPaymentById = async (req, res, next) => {
    id = req.params.id;

    try {
        const payment = await Payment.findById(id).exec();
        if(payment) {
            const obj = {};
            obj._id = payment._id;
            obj.amounts = payment.amounts;
            res.status(200).json(obj);
        }
        else {
            res.status(404).json();
        }

    } catch(error) {
        next(error)
    }
}


module.exports.patchPayment = async (req, res, next) => {
    id = req.body.id;
    amount = req.body.amount;
    if(!amount || !id){
        res.status(500).json();
        return ;
    }

    try {

        let payment = await Payment.find({ _id: id }).exec();
        if(!payment) {
            res.status(404).json();
        } 
        else {
            payment[0].amounts.push(amount);
            await payment[0].save();
            res.status(200).send({ message: "success" });
        }

    } catch(error) {
        next(error);
    }
}
