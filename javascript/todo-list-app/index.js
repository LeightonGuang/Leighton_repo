const textarea = document.getElementById('todo');

textarea.value = '';

const enterButton = document.getElementById('enterButton');

enterButton.addEventListener('click', function handleClick() {
    console.log(textarea.value);

    textarea.value = '';
});