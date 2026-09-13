//Lógica: Verifica se ocorre algo que não era para ocorrer. Caso ocorra, retorna falso. Caso não, retorna true no final
function isValidIPv4(ipv4) {

  let ipv4_Character = ipv4.split('.');

  if(ipv4_Character.length != 4 ){
    return false; 
  } // verifies if ipv4 has 4 subsets

  for(let i =0; i<ipv4_Character.length; i++){
    if(ipv4_Character[i]===''){
      return false; 
    } // verifies if the subset array is "empty"
    if (Number(ipv4_Character[i]) < 0 || Number(ipv4_Character[i]) > 255){ 
      
      return false 
      } // verifies if ever subset is between 0 and 255    

    let vector_SubSet = ipv4_Character[i].split("")

      if(vector_SubSet.length>1){
        
        if (vector_SubSet[0]==='0' ){
          return false
       } // verifies if the fist number is 0 
      }
      for(let j = 0; j<vector_SubSet.length; j++){

        if (vector_SubSet[j].charCodeAt(0) < 48 || vector_SubSet[j].charCodeAt(0) > 57){
           return false; 
          } // verifies if ever character is an valid number (0-9)
      }  
    }
  
  return true;
}
/*

SOURCE: freeCodingCamp - Daily Coding Challenge (05/09/2026)


*/ 