/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    let mat = [];
    if(rowsCount*colsCount != this.length){
        return mat;
    }
    for(let i = 0 ;i<rowsCount ; i++){
        let temp = [];
        mat.push(temp);
    }
    let i = 0;
    for(let col = 0 ; col < colsCount ; col++){
        if(col % 2 === 0){
            //top to bottom
            for(let k = 0 ; k<rowsCount; k++){
                mat[k].push(this[i++]);
            }
        }
        else{
            //bottom to top
            for(let k = (rowsCount-1) ; k>=0; k--){
                mat[k].push(this[i++]);
            }
        }
    }
    /*let flip = false;
    let j = 0;
    for(let i = 0 ;i<this.length ; i++){
        mat[j].push(this[i]);
        if(flip === false){
            j++;
            if(j >= (colsCount-1)){
                j = (colsCount - 1);
                flip = true;
                continue;
            } 
        }
        if(flip === true){
            j--;
            if(j<=0){
                j = 0;
                flip = false;
                continue;
            }
        }
    }*/

    return mat;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */