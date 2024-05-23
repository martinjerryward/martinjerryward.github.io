https://martinjerryward.github.io

git add . && git commit -m "Your commit message here" && git push origin main



<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Telegram Bot API Example</title>
</head>
<body>
  <h1>Telegram Bot API Example</h1>
  <button onclick="sendMessage()">Send Message</button>

  <script>
    // Function to send a message using the Telegram Bot API
    async function sendMessage() {
    //   const BOT_TOKEN = 'YOUR_BOT_TOKEN'; // Replace with your bot token
      const BOT_TOKEN = '6994686412:AAHEXDkv-OGlhZcJCbeXCOUCHkJkWpqMsV0'; // Replace with your bot token
    //   const CHAT_ID = 'YOUR_CHAT_ID'; // Replace with your chat ID
      const CHAT_ID = '6801102860'; // Replace with your chat ID
      const MESSAGE_TEXT = 'Hello from my website!';

      const url = `https://api.telegram.org/bot${BOT_TOKEN}/sendMessage`;
      const params = {
        chat_id: CHAT_ID,
        text: MESSAGE_TEXT
      };

      try {
        const response = await fetch(url, {
          method: 'POST',
          headers: {
            'Content-Type': 'application/json'
          },
          body: JSON.stringify(params)
        });

        if (response.ok) {
          alert('Message sent successfully!');
        } else {
          alert('Failed to send message. Please check the console for details.');
          console.error('Failed to send message:', response.statusText);
        }
      } catch (error) {
        alert('An error occurred while sending the message. Please check the console for details.');
        console.error('Error sending message:', error);
      }
    }
  </script>
</body>
</html>
