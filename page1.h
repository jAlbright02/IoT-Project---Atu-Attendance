String WebSitePage1Pt1 = F(R"=====(

<!DOCTYPE html>
    <html>
    <head>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'/>
    <meta charset='utf-8'>
  <title>ATU-Attendance</title>
  </head>

  
    
  <script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>

    <script> 
    function clickchange(curClass) {
        var ptag = document.getElementById('classNow');
    if (curClass === 'IOT') {
      ptag.innerHTML = 'IOT Class';
    }
    else if (curClass === 'Prog') {
      ptag.innerHTML = 'Programming Class';
    }
    else if (curClass === 'CompEng') {
      ptag.innerHTML = 'Computer Eng Class';
    }
    else if (curClass === 'Maths') {
      ptag.innerHTML = 'Maths Class';
    }
    else if (curClass === 'EDA') {
      ptag.innerHTML = 'EDA Class';
    }
    else if (curClass === 'AnDev') {
      ptag.innerHTML = 'Analog Devices Class';
    }
    else if (curClass === 'IntTech') {
      ptag.innerHTML = 'Internet Tech Class';
    }
    }
  </script>

  <script>
    function resetString() {
      fetch('/reset') // Send a GET request to the "/reset" endpoint
        
    }
  </script>
  
  <style>
  
  body {
    font-family: sans-serif;
  padding: 2em;
  }
  
  .wrapper {
  display: flex;
  flex-flow: row wrap;
  font-weight: bold;
  text-align: center;
  
  }
  
  .wrapper > * {
  padding: 10px;
  flex: 1 100%;
  border-radius: 5px;
  }
  
  .header {
  background: #005b5e;
  color: #7bb9cb;
  font-size: 60px;
  top:50%;
  }
  
  .footer {
  background: #001a79;
  color: white;
  font-size: 20px ;
  }
  
  .main {
  text-align: center;
  background: white;
  }
  
  .selectClass {
  background: #7bb9cb;
  font-size: 20px ;
  text-align: center;
  }
  
  .dropdown {
  font-size: 15px;
  }
  
  .schoolInfo {
  background: #7bb9cb;
  font-size: 20px;
  }
  
  table, th, td {
      border: 2px solid;
      font-size: 35px ;
    
    }
    
  table.tableStudent {
    width: 100%;
    text-align: center;
    margin: 20px;
      margin-left: auto;
      margin-right: auto;
    }
  
  @media all and (min-width: 600px){
    .aside { 
      flex: 1 0 0;
    }
  }

  @media all and (min-width: 800px){
  .main { flex: 3;}
  .selectClass { order: 1;}
  .main { order: 2; }
  .schoolInfo { order: 3; }
  .footer { order: 4; }
  }
  
  .tableHeaders {
  text-align: center;
  font-size: 35px;
  margin: 10px;
  }
  
  .classButtons {
  display: flex;
  font-size: 35px;
  border-radius: 10px;
  flex-direction: column;
  width: 100%;
  margin-right: 5px;
  margin-bottom: 5px;
  padding: 5px;
  } 

  #asideTitles {
  font-size: 40px;
  color: #005b5e;
  margin: 0px;
  }
  
  img {
  float:left;
  padding-top:15px;
  }
  
  </style>
  
  <body>
  <div class="wrapper">
  
  <header class="header">
  <img src="https://cdn.onlinewebfonts.com/svg/img_72363.png" alt="Refresh" onclick="location.reload()" width="40" height="40">
  Welcome to ATU Attendance
  </header>
  
  <article class="main">
  
  <p id="classNow" class="tableHeaders">Current Class</p>
  
  <table class="tableStudent">
  <tr>
    <th>Firstname</th>
    <th>Lastname</th>
    <th>Attended</th>
    
  </tr>
  <tr>
    <td>Patrick</td>
    <td>Feeney</td>
    <td>)====="); String WebSitePage1Pt2 = F(R"=====(</td>
    
    
  </tr>
  <tr>
    <td>Mark</td>
    <td>Veersingham</td>
    <td>)====="); String WebSitePage1Pt3 = F(R"=====(</td>
    
  </tr>
  <tr>
    <td>James</td>
    <td>Albright</td>
    <td>)====="); String WebSitePage1Pt4 = F(R"=====(</td>
   
  </tr>

  <tr>
    <td>Ciara</td>
    <td>Crowe</td>
    <td>)====="); String WebSitePage1Pt5 = F(R"=====(</td>
   
  </tr>
  
  </table>
  
  </article>
  
  
  <aside class="aside selectClass">
  <p id="asideTitles"> Classes </pr>
  <hr></hr>
  <button class="classButtons" onclick="clickchange('IOT')">IoT</button>
  <button class="classButtons" onclick="clickchange('Prog')">Programming</button>
  <button class="classButtons" onclick="clickchange('CompEng')">Computer Eng</button>
  <button class="classButtons" onclick="clickchange('Maths')">Maths</button>
  <button class="classButtons" onclick="clickchange('EDA')">EDA</button>
  <button class="classButtons" onclick="clickchange('AnDev')">Analog Devices</button>
  <button class="classButtons" onclick="clickchange('IntTech')">Internet Tech</button>
  <hr></hr>
  <p id="asideTitles"> Tools </p>
  <hr></hr>
  <button class="classButtons" onclick="resetString()">Reset Values</button>

  
  </aside>
  
  <aside class="aside schoolInfo">
  <a class="twitter-timeline" dnt="true" data-height="750" widget_type="grid" href="https://twitter.com/ATU_GalwayCity?ref_src=twsrc%5Etfw">
  Tweets by ATU_GalwayCity
  </a>
  </aside>
  
  <footer class="footer">Powered by esp32</footer>
 </div>
  
 </body>
 </html>

 )=====");
