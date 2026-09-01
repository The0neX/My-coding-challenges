function calcStrength(letter){
  let letter_Strength = 0;
  let ascii_code = letter.charCodeAt(0);
  if(ascii_code>=48 && ascii_code<=57){ // retorna o valor correspondente do numero
    letter_Strength = ascii_code - 48;
  }
  if(ascii_code>=97 && ascii_code<=122){  //retorna o valor de 1-26
    letter_Strength = ascii_code - 96;
  }
  if(ascii_code>=65 && ascii_code<=90){ //retorna valor de 27-52                                              
    letter_Strength = ascii_code - 38;                                              
  }

  return letter_Strength;
}

function battle(myArmy, opposingArmy) {

  if(!(myArmy.length===opposingArmy.length)){
  let return_string = (myArmy.length>opposingArmy.length) ? "Opponent retreated" : "We retreated";
  return return_string;
  }

  let return_string;
  let my_win_points = 0;
  let opponent_win_points = 0;

  for(let i=0; i<myArmy.length; i++){
    
    let my_Letter_Strength = calcStrength(myArmy[i]);
    let opposing_Letter_Strength = calcStrength(opposingArmy[i]);
    if(my_Letter_Strength === opposing_Letter_Strength) {
        my_win_points++;
        opponent_win_points++;
    } else{
    (my_Letter_Strength>opposing_Letter_Strength) ? my_win_points++ : opponent_win_points++;
    }
  }
    console.log(my_win_points);
    console.log(opponent_win_points);

  if(my_win_points === opponent_win_points){
    return_string = "It was a tie";
  } else{
  return_string = (my_win_points>opponent_win_points) ? "We won"  : "We lost";
  }
  console.log(return_string)
  return return_string;
  
}
battle("Wizards", "Dragons")
/*

SOURCE: freeCodingCamp - Daily Coding Challenge (24/08/2026)


*/ 
