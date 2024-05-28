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






FIREBASE START

<!DOCTYPE html>
<html>
<head>
    <title>Firebase Auth Example</title>
    <script src="https://www.gstatic.com/firebasejs/9.6.1/firebase-app.js"></script>
    <script src="https://www.gstatic.com/firebasejs/9.6.1/firebase-auth.js"></script>
    <script src="https://www.gstatic.com/firebasejs/9.6.1/firebase-database.js"></script>
</head>
<body>
    <h1>Firebase Auth Example</h1>
    <div id="auth">
        <input type="email" id="email" placeholder="Email">
        <input type="password" id="password" placeholder="Password">
        <button id="signUpButton">Sign Up</button>
        <button id="signInButton">Sign In</button>
    </div>
    <button id="incrementButton" style="display:none;">Increment</button>

    <script type="module">
    import { initializeApp } from "https://www.gstatic.com/firebasejs/9.6.1/firebase-app.js";
    import { getAuth, createUserWithEmailAndPassword, signInWithEmailAndPassword, onAuthStateChanged } from "https://www.gstatic.com/firebasejs/9.6.1/firebase-auth.js";
    import { getDatabase, ref, get, set } from "https://www.gstatic.com/firebasejs/9.6.1/firebase-database.js";

    const firebaseConfig = {
        apiKey: "AIzaSyDmrosbaex2WMuE0VaBmIerGHZnA9QrjTY",
        authDomain: "telecloud-bc8f6.firebaseapp.com",
        databaseURL: "https://telecloud-bc8f6-default-rtdb.firebaseio.com",
        projectId: "telecloud-bc8f6",
        storageBucket: "telecloud-bc8f6.appspot.com",
        messagingSenderId: "668489036908",
        appId: "1:668489036908:web:1eb80c7cded126b00a5449",
        measurementId: "G-303FRT62KT"
    };

    const app = initializeApp(firebaseConfig);
    const auth = getAuth(app);
    const db = getDatabase(app);

    document.getElementById('signUpButton').addEventListener('click', async () => {
        const email = document.getElementById('email').value;
        const password = document.getElementById('password').value;
        try {
            const userCredential = await createUserWithEmailAndPassword(auth, email, password);
            const uid = userCredential.user.uid;
            await set(ref(db, 'users/' + uid), {
                email: email,
                role: 'user',
                data: { counter: 0 }
            });
            console.log('User signed up and data initialized');
        } catch (error) {
            console.error('Error signing up:', error);
        }
    });

    document.getElementById('signInButton').addEventListener('click', async () => {
        const email = document.getElementById('email').value;
        const password = document.getElementById('password').value;
        try {
            await signInWithEmailAndPassword(auth, email, password);
            console.log('User signed in');
        } catch (error) {
            console.error('Error signing in:', error);
        }
    });

    onAuthStateChanged(auth, (user) => {
        if (user) {
            document.getElementById('incrementButton').style.display = 'block';
        } else {
            document.getElementById('incrementButton').style.display = 'none';
        }
    });

    document.getElementById('incrementButton').addEventListener('click', async () => {
        const uid = auth.currentUser.uid;
        const counterRef = ref(db, 'users/' + uid + '/data/counter');
        const snapshot = await get(counterRef);

        if (snapshot.exists()) {
            const currentValue = snapshot.val();
            await set(counterRef, currentValue + 1);
        } else {
            await set(counterRef, 1);
        }

        console.log("Incremented!");
    });
    </script>
</body>
</html>


