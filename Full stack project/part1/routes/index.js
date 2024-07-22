var express = require('express');
var router = express.Router();
var sanitizeHtml = require('sanitize-html');

/* GET home page. */
router.get('/', function (req, res, next) {
  res.render('index', { title: 'Express' });
});

router.get('/get_trip', function (req, res, next) {
  req.pool.getConnection(function (err, connection) {
    if (err) {
      res.sendStatus(500);
      console.log("error");
      return;
    }
    var query = '';

    if ('trip_id' in req.query) {
      var trip_id = req.query.trip_id;
      query = "SELECT * FROM Trip WHERE trip_id=?;";
      connection.query(query, trip_id, function (Qrerr, result) {
        connection.release();
        if (Qrerr) {
          res.sendStatus(500);
          console.log("error database");
          return;
        }
        // console.log(result);
        res.json(result);
      });
    } else {
      query = "SELECT * FROM Trip";
      connection.query(query, function (Qrerr, result) {
        connection.release();
        if (Qrerr) {
          res.sendStatus(500);
          console.log("error database");
          return;
        }
        res.json(result);
      });
    }
  });

});

router.post('/get_trip_sorted', function (req, res, next) {
  const { destination, duration, start_date, end_date, tripType, user_id } = req.body;

  req.pool.getConnection(function (err, connection) {
    if (err) {
      res.sendStatus(500);
      console.log("error");
      return;
    }
    var query = '';
    if (tripType === 'hasTravelled') {
      query = "SELECT * FROM (Trip INNER JOIN Booking ON Trip.trip_id = Booking.trip_id) WHERE Booking.user_id =? AND Trip.end_date <= now();";
      connection.query(query, user_id, function (Qrerr, result) {
        connection.release();
        if (Qrerr) {
          res.sendStatus(500);
          console.log("error database");
          return;
        }
        // console.log(result);
        res.json(result);
      });
    } else if (tripType === 'allTrips') {
      // console.log("get all trips");
      query = "SELECT * FROM Trip";
      connection.query(query, function (Qrerr, result) {
        connection.release();
        if (Qrerr) {
          res.sendStatus(500);
          console.log("error database");
          return;
        }
        // console.log(result);
        res.json(result);
      });
    } else if (tripType === 'upComming') {
      // console.log("get all trips");
      query = "SELECT * FROM Trip WHERE Trip.start_date >= now()";
      connection.query(query, function (Qrerr, result) {
        connection.release();
        if (Qrerr) {
          res.sendStatus(500);
          console.log("error database");
          return;
        }
        // console.log(result);
        res.json(result);
      });
    }
  });
});

router.get('/get_name', function (req, res, next) {
  req.pool.getConnection(function (err, connection) {
    if (err) {
      res.sendStatus(500);
      console.log("error");
      return;
    }
    if ('id' in req.query) {
      var user_id = req.query.id;
      var query = "SELECT first_name, last_name FROM Account WHERE account_id=?;";

      connection.query(query, user_id, function (Qrerr, result) {
        connection.release();
        if (Qrerr) {
          res.sendStatus(500);
          console.log("error database");
          return;
        }
        // console.log(result);
        res.json(result);
      });
    }
  });
});

router.get('/get_review', function (req, res, next) {
  req.pool.getConnection(function (err, connection) {
    if (err) {
      res.sendStatus(500);
      console.log("error");
      return;
    }
    if ('trip_id' in req.query) {
      var trip_id = req.query.trip_id;
      var query = "SELECT first_name, last_name, feedback_date, title_feedback, comment FROM (Feedback INNER JOIN Account ON Feedback.user_id = Account.account_id) WHERE Feedback.trip_id=? ORDER BY feedback_date DESC;";

      connection.query(query, trip_id, function (Qrerr, result) {
        connection.release();
        if (Qrerr) {
          res.sendStatus(500);
          console.log("error database");
          return;
        }
        // console.log(result);
        res.json(result);
      });
    }
  });
});

router.post('/post_comment', function (req, res, next) {
  const { fbTitle, comment, Post_as, trip_id, user_id } = req.body;
  // console.log(req.body);
  req.pool.getConnection(function (err, connection) {
    if (err) {
      res.sendStatus(500);
      console.log("error");
      return;
    }
    var query = '';

    if (Post_as === 'Anonymous') {
      query = "INSERT INTO Feedback VALUES(NULL, ?, ?, CURRENT_TIMESTAMP, 1, ?);";

      connection.query(query, [sanitizeHtml(fbTitle), sanitizeHtml(comment), trip_id], function (Qrerr, result) {
        connection.release();
        if (Qrerr) {
          res.sendStatus(500);
          console.log("error database1");
          return;
        }
        // console.log(result);
        res.json(result);
      });
    } else {
      query = "INSERT INTO Feedback VALUES(NULL, ?, ?, SYSDATE(), ?, ?);";

      connection.query(query, [sanitizeHtml(fbTitle), sanitizeHtml(comment), user_id, trip_id], function (Qrerr, result) {
        connection.release();
        if (Qrerr) {
          res.sendStatus(500);
          console.log("error database2");
          return;
        }
        // console.log(result);
        res.json(result);
      });
    }

  });
});

router.get('/get_review_manager', function (req, res, next) {
  req.pool.getConnection(function (err, connection) {
    if (err) {
      res.sendStatus(500);
      console.log("error");
      return;
    }
    if ('manager_id' in req.query) {
      var manager_id = req.query.manager_id;
      var query = "SELECT first_name, last_name, feedback_date, title_feedback, comment, title FROM ((Trip INNER JOIN Account ON Trip.manager_id = Account.account_id) INNER JOIN Feedback ON Trip.trip_id = Feedback.trip_id)  WHERE Account.account_id=? ORDER BY feedback_date DESC;";

      connection.query(query, manager_id, function (Qrerr, result) {
        connection.release();
        if (Qrerr) {
          res.sendStatus(500);
          console.log("error database");
          return;
        }
        // console.log(result);
        res.json(result);
      });
    }
  });
});

module.exports = router;
