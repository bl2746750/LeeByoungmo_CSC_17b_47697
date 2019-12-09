<?php

//answer true or false
function check_game_currently_playing(){
    require 'loginMysql_1.php';
    $query="SELECT game_id FROM entity_game WHERE status=1";
    $result=mysqli_query($link,$query);
    //$rows=mysqli_num_rows($result);
    
    //echo $rows;
    return $rows;
}

function create_game($num_players){
    require 'loginMysql_1.php';
    $query="INSERT INTO entity_game VALUES (NULL,1,0,$num_players,NULL,NULL)";
    $result=$link->query($query);
    $game_id= $link->insert_id;
    if(!$result) echo "CREATE GAME failed!";
    return $game_id;
}  

function get_playing_game_id(){
    require 'loginMysql_1.php';
    $query="SELECT game_id FROM entity_game WHERE status=1";
    $result=mysqli_query($link,$query);
    $rows=mysqli_num_rows($result);
    if($rows == 0) {return -1;}
    else {
        $row=mysqli_fetch_array($result,MYSQLI_ASSOC);
        return $row['game_id'];    
    }
}

function get_game_status($game_id){
    require 'loginMysql_1.php';
    $query="SELECT status FROM entity_game WHERE status=1";
    $result=mysqli_query($link,$query);
    $rows=mysqli_num_rows($result);
    if($rows == 0) {return -1;}
    else {
        $row=mysqli_fetch_array($result,MYSQLI_ASSOC);
        return $row['status'];    
    }
}

function retrieve_mycards($game_id, $p_id){
    require 'loginMysql_1.php';
    $query="SELECT p_cards FROM xref_play_game WHERE game_id=$game_id and p_id=$p_id";
    $result=mysqli_query($link,$query);
    if(!$result) die("Failure to retrieve players cards");
    $rows=mysqli_num_rows($result);
    
    if($rows == 0) {return -1;}
    else {
        $row=mysqli_fetch_array($result,MYSQLI_ASSOC);
        //print_r($row['p_cards']);
        return $row['p_cards'];    
    }
}

function retrieve_dcards($game_id){
    require 'loginMysql_1.php';
    $query="SELECT dcards_array FROM entity_game WHERE game_id=$game_id";
    $result=mysqli_query($link,$query);
    $rows=mysqli_num_rows($result);
    if($rows == 0) {return -1;}
    else {
        $row=mysqli_fetch_array($result,MYSQLI_ASSOC);
        return $row['dcards_array'];    
    }
}

function update_dcards($game_id,$dCards){
    require 'loginMysql_1.php';
    $query="UPDATE entity_game SET dcards_array='$dCards' WHERE game_id=$game_id";
    $result=$link->query($query);
}

function update_game_stage($game_id,$stage){
    require 'loginMysql_1.php';
    $query="UPDATE entity_game SET stage='$stage' WHERE game_id=$game_id";
    $result=$link->query($query);
}

function get_game_stage($game_id){
    require 'loginMysql_1.php';
    $query="SELECT stage FROM entity_game WHERE game_id=$game_id";
    $result=mysqli_query($link,$query);
    $rows=mysqli_num_rows($result);
    if($rows == 0) {return -1;}
    else {
        $row=mysqli_fetch_array($result,MYSQLI_ASSOC);
        return $row['stage'];    
    }
}

function update_display_cards($game_id,$display_cards){
    require 'loginMysql_1.php';
    $query="UPDATE entity_game SET display_cards='$display_cards' WHERE game_id=$game_id";
    $result=$link->query($query);
}

function get_display_cards($game_id){
    require 'loginMysql_1.php';
    $query="SELECT display_cards FROM entity_game WHERE game_id=$game_id";
    $result=mysqli_query($link,$query);
    $rows=mysqli_num_rows($result);
    if($rows == 0) {return -1;}
    else {
        $row=mysqli_fetch_array($result,MYSQLI_ASSOC);
        return $row['display_cards'];    
    }
}

// function get_available_game_id($num_players){
//    $game_id= check_available_game_id();
//    //echo "game_id=".$game_id."<br />";
//    if($game_id<0){
//        
//        $game_id=create_game($num_players);
//    }
//    update_avail_game_to_playing($game_id);
//    return $game_id;
//}


//removed since we only have 2 status
// function check_available_game_id(){
//    require 'loginMysql_1.php';
//    $query="SELECT game_id FROM entity_game WHERE status=1";
//    $result=mysqli_query($link,$query);
//    $rows=mysqli_num_rows($result);
//    if($rows == 0) {return -1;}
//    else {
//        $row=mysqli_fetch_array($result,MYSQLI_ASSOC);
//        return $row['game_id'];    
//    }
//}



// function update_avail_game_to_playing($game_id){
//    require 'loginMysql_1.php';
//    $stmt=mysqli_prepare($link,"UPDATE entity_game SET status=2 WHERE game_id=$game_id");
//    mysqli_stmt_execute($stmt);
//    echo mysqli_error($link);
//}    
