const mongoose = require('mongoose');

const paymentSchema = mongoose.Schema({
    _id: mongoose.Types.ObjectId,
    name: {
        type: String
    },
    surname: {
        type: String
    },
    email: {
        type: String
    },
    amounts: {
        type: [Number]
    }
});

const PaymentModel = mongoose.model('Payment', paymentSchema);

module.exports = PaymentModel;