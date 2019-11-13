<?php 
include "inc/header.php";
include "inc/Deal.php";
include "inc/HandlersInit.php";
include "inc/view.php";
?>
<!DOCTYPE html>
<!--
    Created on : October 12, 2019, 00:59:09 AM
    Purpose    : texas Holdem 
-->
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Texas Holdem</title>
        <link rel="stylesheet" type="text/css" href="css/skeleton.css">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>
        
    </head>
    
    <body>
        <div id="board">
            <div id="messageArea"></div>
            <table>
                <tr>
                    <td id="000">000</td> <td id="001">001</td> 
                    <td id="002">002</td> <td id="003">003</td>
                    <td id="004">004</td> <td id="005">005</td> 
                    <td id="006">006</td> <td id="007">007</td>
                    <td id="008">008</td> <td id="009">009</td> 
                    <td id="010">010</td> <td id="011">011</td>
                    <td id="012">012</td> <td id="013">013</td> 
                    <td id="014">014</td> <td id="015">015</td>
                    
                </tr>
                <tr>
                    <td id="100">100</td> <td id="101">101</td> 
                    <td id="102">102</td> <td id="103">103</td>
                    <td id="104">104</td> <td id="105">105</td> 
                    <td id="106">106</td> <td id="107">107</td>
                    <td id="108">108</td> <td id="109">109</td> 
                    <td id="110">110</td> <td id="111">111</td>
                    <td id="112">112</td> <td id="113">113</td> 
                    <td id="114">114</td> <td id="115">115</td>
                    
                </tr>
                <tr>
                    <td id="200">200</td> <td id="201">201</td> 
                    <td id="202">202</td> <td id="203">203</td>
                    <td id="204">204</td> <td id="205">205</td> 
                    <td id="206">206</td> <td id="207">207</td>
                    <td id="208">208</td> <td id="209">209</td> 
                    <td id="210">210</td> <td id="211">211</td>
                    <td id="212">212</td> <td id="213">213</td> 
                    <td id="214">214</td> <td id="215">215</td>
                   
                </tr>
                
            </table>
            
            
            
        </div>
        <div class="container">
            <br><br>
            <button type="button" id ="initGame" class="btn btn-primary">Ready to Play!</button>
        </div>
        
    </body>
</html>