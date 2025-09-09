/// <reference path="./global.d.ts" />
// @ts-check

/**
 * Implement the functions needed to solve the exercise here.
 * Do not forget to export them so they are available for the
 * tests. Here an example of the syntax as reminder:
 *
 * export function yourFunction(...) {
 *   ...
 * }
 */
export function cookingStatus(remainingTime) {
    switch (remainingTime) {
        case 0:
            return 'Lasagna is done.';
        case undefined:
            return 'You forgot to set the timer.';
        default:
            return 'Not done, please wait.';
    }
}

export function preparationTime(layers, time) {
    return layers.length * (time ?? 2);
}

export function quantities(layers) {
    let noodleCount = 0;
    let sauceCount = 0;

    for (let i = 0; i < layers.length; i++) {
        if (layers[i] === 'noodles') {
            noodleCount++;
        } else if (layers[i] === 'sauce') {
            sauceCount++;
        }
    }

    return {
        'noodles': noodleCount * 50,
        'sauce': sauceCount * 0.2
    };
}

export function addSecretIngredient(friendsList, myList) {
    myList.push(friendsList[friendsList.length - 1]);
}

export function scaleRecipe(recipe, portions) {
    let newRecipe = structuredClone(recipe);
    let scale = portions / 2;

    for (let key in newRecipe) {
        newRecipe[key] *= scale;
    }

    return newRecipe;
}