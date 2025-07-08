<?php

$re = [
    200 => 'OK',
    400 => 'Bad Request',
    401 => 'Unauthorized',
    403 => 'Forbidden',
    404 => 'Not Found',
    500 => 'Internal Server Error',
    502 => 'Bad Gateway',
    503 => 'Service Unavailable'
];

if (isset($_GET['code'])) {
    $code = intval($_GET['code']);

    if (array_key_exists($code, $re)) {
        http_response_code($code);
        echo "$code " . $re[$code] . "<br><img src=\"https://http.cat/$code\">";
    } else {
        http_response_code(400);
        echo "Error" . "<br><img src=\"https://http.cat/$code\">";
    }
} else {
    http_response_code(400);
    echo "Error" . "<br><img src=\"https://http.cat/$code\">";
}

?>
