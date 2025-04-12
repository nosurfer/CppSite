function sendPost() {
    const name = document.getElementById('postName').value;
    const data = document.getElementById('postData').value;
    const payload = {
        name: name,
        data: data
    };

    fetch('/api/data', {
        method: 'POST',
        headers: {
        'Content-Type': 'application/json'
        },
        body: JSON.stringify(payload)
    })
    .then(response => response.json())
    .then(result => {
        document.getElementById('response').innerText = 'POST Response: ' + JSON.stringify(result);
    })
    .catch(error => {
        document.getElementById('response').innerText = 'Ошибка POST запроса: ' + error;
    });
}

function sendGet() {
    const name = document.getElementById('getName').value;
    fetch('/api/data?name=' + encodeURIComponent(name))
    .then(response => response.json())
    .then(result => {
        document.getElementById('response').innerText = 'GET Response: ' + JSON.stringify(result);
    })
    .catch(error => {
        document.getElementById('response').innerText = 'Ошибка GET запроса: ' + error;
    });
}