import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Deque;

import common.TreeNode;


/**
 * @link https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 * 
 * @level easy
 * 
 * @tag binary tree
 * @tag 二叉树
 * @tag preorder traversal
 * @tag 前序遍历
 */
class Solution144BinaryTreePreorderTraversal {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if (root == null) {
            return res;
        }

        Deque<TreeNode> stack = new LinkedList<TreeNode>();
        TreeNode node = root;
        while (!stack.isEmpty() || node != null) {
            while (node != null) {
                res.add(node.val);
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            node = node.right;
        }
        return res;
    }
}