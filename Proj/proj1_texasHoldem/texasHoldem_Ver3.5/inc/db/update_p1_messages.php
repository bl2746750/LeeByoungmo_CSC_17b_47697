<?php
include 'user_board.php';

//session_start();

$p_id=1;
$tag=user_board_tag($p_id);

return $tag;

