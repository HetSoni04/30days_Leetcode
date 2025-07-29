/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    arr = this;
    let result = {};
    for(let i = 0; i<this.length; i++){
        let key = fn(arr[i])
        if(result.hasOwnProperty(key)){
            //append the 'i'
            result[key].push(arr[i]); 
        }
        else{
            //need to add the property
            result[key] = []
            result[key].push(arr[i])
        }
    }
    return result
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */