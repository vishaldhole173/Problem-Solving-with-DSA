<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration form</title>
</head>
<body>

    <div>
    <?php
    if(isset($_POST['register']){
        echo 'You are registered sucessfully';
    }
    ?>
    </div>

    <div>
    <form action="registration.php" method="POST">
    <div class="container">
    <h1>Speaker Registration</h1>
    
    <br>

    <label for="FirstName" <b>First Name</b> ></label>
    <input type="text" name="FirstName" required>

    <label for="MiddleName"><b>Middle Name</b></label>
    <input type="text" name="MiddleName" required>

    <label for="LastName"<b>Last Name</b>></label>
    <input type="text" name="LastName" required>

    <label for="email"<b>Email</b>></label>
    <input type="email" name="email" required>

    <label for="phone"<b>Mobile Number</b>></label>
    <input type="text" name="phone" required>

    <label for="username"><b>User Name</b></label>
    <input type="text" name="username" required>

    <label for="password" <b>Password</b>></label>
    <input type="password" name="password" required>

    <input type="submit" name="register" value="Sign Up">
    </div>
    </form>
    </div>
</body>
</html>