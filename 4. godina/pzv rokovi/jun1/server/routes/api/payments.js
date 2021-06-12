const express = require('express');
const router = express.Router();
const controller = require('../../controllers/paymentController');

router.get('/email/:email', controller.getPaymentByEmail);
router.get('/id/:id', controller.getPaymentById);
router.patch('/', controller.patchPayment);

module.exports = router;
